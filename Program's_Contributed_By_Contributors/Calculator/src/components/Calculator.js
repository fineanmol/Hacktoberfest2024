import React from "react";
import "./Calculator.css";
function Calculator() {
  const [calc, setCalc] = React.useState("");

  const operators = ["+", "-", "*", "/", "."];

  const handleClick = (e) => {
    const value = e.target.value;
    if (
      (operators.includes(e.target.value) && calc === "") ||
      (operators.includes(e.target.value) &&
        operators.includes(calc[calc.length - 1]))
    ) {
      return;
    }
    setCalc(calc + value);
    if (value === "C") {
      setCalc("");
    }
  };

  const evaluate = () => {
    const result = (eval(calc));
    setCalc(result);
  };

  return (
    <div className="calculator">
      <form action="">
        <input type="text" value={calc} />
      </form>
      <div className="buttons">
        <button className="calculator-button" value="C" onClick={handleClick}>
          C
        </button>
        <button className="calculator-button" value="%" onClick={handleClick}>
          %
        </button>
        <button className="calculator-button">&larr;</button>
        <button className="calculator-button" value="/" onClick={handleClick}>
          &#247;
        </button>
        <button className="calculator-button" value="7" onClick={handleClick}>
          7
        </button>
        <button className="calculator-button" value="8" onClick={handleClick}>
          8
        </button>
        <button className="calculator-button" value="9" onClick={handleClick}>
          9
        </button>
        <button className="calculator-button" value="*" onClick={handleClick}>
          &times;
        </button>
        <button className="calculator-button" value="4" onClick={handleClick}>
          4
        </button>
        <button className="calculator-button" value="5" onClick={handleClick}>
          5
        </button>
        <button className="calculator-button" value="6" onClick={handleClick}>
          6
        </button>
        <button className="calculator-button" value="-" onClick={handleClick}>
          &minus;
        </button>
        <button className="calculator-button" value="1" onClick={handleClick}>
          1
        </button>
        <button className="calculator-button" value="2" onClick={handleClick}>
          2
        </button>
        <button className="calculator-button" value="3" onClick={handleClick}>
          3
        </button>
        <button className="calculator-button" value="+" onClick={handleClick}>
          +
        </button>
        <button className="calculator-button" value="00" onClick={handleClick}>
          00
        </button>
        <button className="calculator-button" value="0" onClick={handleClick}>
          0
        </button>
        <button className="calculator-button" value="." onClick={handleClick}>
          .
        </button>
        <button className="calculator-button" onClick={evaluate}>
          =
        </button>
      </div>
    </div>
  );
}

export default Calculator;
