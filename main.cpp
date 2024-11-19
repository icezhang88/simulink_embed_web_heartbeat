#include <iostream>
#include "serial/serial.h"
#include "spdlog/spdlog.h"
#include "hv/WebSocketServer.h"
#include "hv/hloop.h"
#include "hv/htime.h"
#include "ThreadPool.h"
#include "set"
#include "nlohmann/json.hpp"
#include "smooth_simu.h"
using namespace std;
ThreadPool*pool=new ThreadPool(10);
using json=nlohmann::json;
int main() {

    smooth_simu* smooth_simu_Obj=new smooth_simu();
    smooth_simu_Obj->initialize();
    smooth_simu::ExtU_smooth_simu_T *pExtU_smooth_simu_T=new smooth_simu::ExtU_smooth_simu_T;
    /**

    for (int i = 0; i < 100; ++i) {
        pExtU_smooth_simu_T->u[i]=test[i];
    }

    smooth_simu_Obj->setExternalInputs(pExtU_smooth_simu_T);
    smooth_simu_Obj->step();
    auto result=smooth_simu_Obj->getExternalOutputs();
    cout<<"result: "<<result.Out1<<endl;
    **/
    vector<int>*sensorData=new vector<int>;

    std::set<WebSocketChannelPtr>*channelSet=new set<WebSocketChannelPtr>;

    WebSocketService*ws=new WebSocketService();
    ws->onopen = [&](const WebSocketChannelPtr& channel, const HttpRequestPtr& req) {
        printf("onopen: GET %s\n", req->Path().c_str());
        // send(time) every 1s
        if (channel->isConnected()){

            channelSet->insert(channel);
            printf("channelSize:%d\r\n",channelSet->size());
        }

    };
    ws->onmessage = [&](const WebSocketChannelPtr& channel, const std::string& msg) {
        printf("onmessage: %s\n", msg.c_str());
    };
    ws->onclose = [&](const WebSocketChannelPtr& channel) {
        printf("onclose\n");
        channelSet->erase(channel);
        printf("channelSize:%d\r\n",channelSet->size());

    };
    websocket_server_t* server=new websocket_server_t;
    pool->enqueue([&]{

        server->port = 9090;
        server->ws = ws;
        websocket_server_run(server);
    });



    std::vector<serial::PortInfo>serialList= serial::list_ports();
    for (const auto &item: serialList){
        spdlog::info("port:{}",item.port);
    }


    serial::Serial* myserial=new serial::Serial("/dev/ttyUSB0",1000000,serial::Timeout::simpleTimeout(1000));
    cout << "Is the serial port open?";
    if(myserial->isOpen())
        cout << " Yes." << endl;
    else
        cout << " No." << endl;

    uint8_t *buffer;
    int heatValue=0;
    json j;
    while (true){
        int availBuf =myserial->available();
        if (availBuf>0){
            //cout<<availBuf<<endl;
            string data=myserial->read(availBuf);
            for(uint8_t byte:data){
                //printf("%d \r\n",byte);
                if (sensorData->size()<100){
                    sensorData->push_back(byte);
                }else{
                    for (int i = 0; i < 100; ++i) {
                        pExtU_smooth_simu_T->u[i]=sensorData->at(i);
                    }
                    smooth_simu_Obj->setExternalInputs(pExtU_smooth_simu_T);
                    smooth_simu_Obj->step();
                    auto result=smooth_simu_Obj->getExternalOutputs();
                    cout<<"heatBeat: "<<result.Out1<<endl;
                    heatValue=result.Out1;
                    sensorData->clear();
                }

                //spdlog::info("byte:{}",(uint8_t)byte);
                //printf("%u\r\n",byte);
                //std::cout << static_cast<unsigned int>(byte) << std::endl;
                j["data"]=(uint8_t)byte;
                j["heartBeat"]=heatValue;
                for (const auto &item: *channelSet){
                    item->send(j.dump());
                }

            }
        }

    }

    return 0;
}
