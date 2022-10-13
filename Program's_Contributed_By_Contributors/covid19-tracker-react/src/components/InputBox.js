import { Card, CardContent, Typography } from "@mui/material";
import React from "react";
import "./InfoBox.css";

const InputBox = (props) => {
  let classes= `infoBox ${props.active && "infoBox--selected"}`;
  if (props.title === "Coronavirus Cases")
    classes = `infoBox infoBox--red ${props.active && "infoBox--selected"}`;
  else if (props.title === "Deaths")
    classes = `infoBox infoBox--orange ${props.active && "infoBox--selected"}`;

  return (
    <Card className={classes} onClick={props.onClick}>
      <CardContent>
        <Typography className="infoBox__title" color="textSecondary">
          {props.title}
        </Typography>
        <h2 className={`"infoBox__cases" ${props.title==="Recovered"&&"infoBox__cases--green"}`}>{props.cases}</h2>
        <Typography className="infoBox__total" color="textSecondary">
          Total:{props.total}
        </Typography>
      </CardContent>
    </Card>
  );
};

export default InputBox;
