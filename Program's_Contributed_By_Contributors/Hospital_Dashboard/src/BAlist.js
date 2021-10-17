import React from 'react';
import { BasicBAtable } from './BasicBAtable';


export const BAlist = () =>(
    <div>
        <div class="container" style={{backgroundColor:"white",borderRadius:"10px", marginTop: "10px", fontSize: "15px", lineHeight: "25.5px", textDecoration: "none solid rgba(0,0,0,0.87)",verticalAlign: "middle", paddingBottom:"11px"}}>
            <div class="row">
                    <h3 style={{fontFamily:"Poppins, sans-serif", fontSize:"20px", fontWeight: "600", lineHeight: "40px", textDecoration:": none solid rgb(58, 64, 91)"}}>TODAY'S APPOINTMENT LIST</h3>
            </div>
            <div class='row'>
               <BasicBAtable />
            </div>
        </div>
    </div>

);
