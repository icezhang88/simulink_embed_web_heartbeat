import logo from './assets/logo.svg';
import './App.css';
import { Routes, Route, Link } from 'react-router-dom';
import About from "./pages/About";
import Home from "./pages/Home";
import { Button,Flex } from 'antd';
const baseStyle = {
    width: '25%',
    height: 54,
};
function App() {
  //增加 HashRouter

  return (
      <div>

        <nav>
          <Link to="/">Home</Link> | <Link to="/about">About</Link>
        </nav>
          <div>


          </div>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
        </Routes>
      </div>
  );
}

export default App;
