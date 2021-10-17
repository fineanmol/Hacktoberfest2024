import React from 'react';
import { Dtable } from './Dtable';


export const Dlist = () =>(
    <div>
        <div class="container" style={{backgroundColor:"white", marginTop: "10px", fontSize: "15px", lineHeight: "25.5px", textDecoration: "none solid rgba(0,0,0,0.87)",borderRadius:"10px",verticalAlign: "middle", paddingBottom:"11px"}}>
            <div class="row">
                    <h3 style={{fontFamily:"Poppins, sans-serif", fontSize:"20px", fontWeight: "600", lineHeight: "40px", textDecoration:": none solid rgb(58, 64, 91)"}}>DOCTORS LIST</h3>
            </div>
            <div class='row'>
               <Dtable />
            </div>
        </div>
    </div>

);
