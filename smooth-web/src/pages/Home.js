import React, {useEffect, useRef,useState } from 'react';
import * as echarts from 'echarts';

export default function Home() {
    const chartRef = useRef(null);
    var count = 1;

    const [heatBeatValue,setHeatBeatValue]=useState(0);
    useEffect(() => {

        if (chartRef.current) {
            // 初始化 ECharts 实例
            const chart = echarts.init(chartRef.current);

            const socket = new WebSocket('ws://192.168.223.128:9090'); // 替换为你的 WebSocket 服务端地址
            // 连接成功
            socket.onopen = () => {
                console.log('WebSocket 连接成功');
                socket.send('Hello Server!'); // 向服务器发送数据
            };


            socket.onmessage = (event) => {
                console.log('收到消息:', event.data); // 处理接收到的消息
                let value = JSON.parse(event.data).data;

                setHeatBeatValue(JSON.parse(event.data).heartBeat);
                //console.info(value)
                count = count + 1;

                options.series[0].data.push(value);
                if (options.xAxis.data.length > 30) {
                    options.xAxis.data.shift()
                    options.series[0].data.shift();
                }
                options.xAxis.data.push(count);

                chart.setOption(options);

            };


            socket.onclose = (event) => {
                console.log('WebSocket 连接关闭:', event.code, event.reason);
            };


            socket.onerror = (error) => {
                console.error('WebSocket 发生错误:', error);
            };

            // 配置图表的选项
            const options = {
                xAxis: {
                    type: 'category',
                    data: ['1', '2', '3', '4', '5', '6', '7']

                },
                yAxis: {
                    type: 'value'
                },
                series: [
                    {
                        data: [0, 0, 0, 0, 0, 0, 0],
                        type: 'line'
                    }
                ]
            };

            console.info("1111111")
            // 使用配置项显示图表
            chart.setOption(options);


            setInterval(() => {
                var ran = parseInt(Math.random() * 10, 10) + 1;


            }, 100)
            // 清理图表实例（在组件卸载时）
            return () => {
                chart.dispose();
            };

        }
    }, []);

    return (
        <div>
            <h1>心率波形圖</h1>
            <h2>心率: {heatBeatValue}</h2>
            {/* 图表容器 */}
            <div
                ref={chartRef}
                style={{width: '100%', height: '400px'}}
            ></div>
        </div>
    );
}
