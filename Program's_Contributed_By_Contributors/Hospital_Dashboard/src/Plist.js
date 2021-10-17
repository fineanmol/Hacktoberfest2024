import React from 'react';
import { BasicTable } from './BasicTable';

const Plist = ()=>(
    <div>
        <div class="container" style={{backgroundColor:"white", marginTop: "10px", fontSize: "15px", lineHeight: "25.5px", textDecoration: "none solid rgba(0,0,0,0.87)",verticalAlign: "middle", paddingBottom:"11px",borderRadius:"10px"}}>
            <div class="row">
                    <h3 style={{fontFamily:"Poppins, sans-serif", fontSize:"20px", fontWeight: "600", lineHeight: "40px", textDecoration:": none solid rgb(58, 64, 91)"}}>NEW PATIENT LIST</h3>
            </div>
            <div class='row'>
                <BasicTable />
            </div>
        </div>
    </div>
);

export default Plist;