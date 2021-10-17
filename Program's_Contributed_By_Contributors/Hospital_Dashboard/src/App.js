import React from 'react';
import './App.css';
import Card from './Card';
import BChart from './BChart';
import PChart from './PChart';
import Plist from './Plist';
import Todo from './Todo';
import { BAlist } from './BAlist';
import { Dlist } from './Dlist';

const App = ()=>{
  return (
    <div class="container">
      <div class="row"><h2>Dashboard</h2></div>
      <div class="row" >
        <div class="col-3"><Card title="Appointment" total="450" description="10 Prec. Since last month" /></div>
        <div class="col-3"><Card title="New Patient" total="254" description="18 Perc. Since last month" /></div>
        <div class="col-3"><Card title="Today's Visit" total="765" description="10 Perc. Since last month"/></div>
        <div class="col-3"><Card title="Visitors" total="323" description="14 Perc. Since last month"/></div>
      </div>
      <div class="row">
          <div class="col-6"><BChart /></div>
          <div class="col-6"><PChart /></div>
      </div>
      <div class="row">
        <div class="col-md-8"><Plist /></div>
        <div class="col-md-4"><Todo /></div>
      </div>
      <div class="row">
        <div class="col-md-8"><BAlist /></div>
        <div class="col-md-4"><Dlist /></div>
      </div>
      <div class="row" style={{backgroundColor:"#222C3C"}}> 
        <footer style={{height:"60px"}}>
              <span style={{color:"white", textAlign:"right", paddingLeft:"350px", fontFamily:"Poppins, sans-serif"}}>Made by Wesign Techonology. Designed by Reshul</span>
        </footer>
      </div>
    </div>
  );
}


export default App;