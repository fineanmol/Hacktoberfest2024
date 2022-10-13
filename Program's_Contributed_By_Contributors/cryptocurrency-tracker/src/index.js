import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";
import App from "./App";
import "react-alice-carousel/lib/alice-carousel.css";
import CryptoContext from "./CryptoContext";

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <CryptoContext>
    <App />
  </CryptoContext>
);
