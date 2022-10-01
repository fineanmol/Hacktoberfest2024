import React, { useState } from 'react';
import PropTypes from 'prop-types';
import './textform.css';





export default function TextForm(props) {

    const [text, setText] = useState("");
    const [myText, setMyText] = useState("Copy Text");
    const [myTextColor, setMyTextColor] = useState('primary');

    const Onchange = (event) => {
        setText(event.target.value); // yeh target se value lelega if i try to change
        // yeh target se value lelega if i try to change
        // .target.value text ko change karega set text ko nahi  
    }

    const upperCaseConverter = () => {
        document.getElementById("text-area").style.textTransform = 'uppercase';


    }

    const lowerCaseConverter = () => {
        document.getElementById("text-area").style.textTransform = 'lowercase';


    }

    const capitalizeConverter = () => {

        document.getElementById("text-area").style.textTransform = 'capitalize';

    }

    const boldConverter = () => {

        document.getElementById("text-area").style.fontWeight = 'bold';

    }

    const underlineConverter = () => {

        document.getElementById("text-area").style.textDecoration = 'underline';
    }

    const htmlparser = async () => {

        // let parsedText = parse(text).toString();
        let mytext;

        if ((text === null) || (text === '')){
            return false;}

        else{
             mytext = text.toString();
        }

        let parsedText = mytext.replace(/<[^>]*>/g, '');

        // console.log(parsedText);

        setText(parsedText);
    }

    const clear = () => {
        document.getElementById("text-area").style.textDecoration = '';
        document.getElementById("text-area").style.fontWeight = '';
        document.getElementById("text-area").style.textTransform = '';
        let newText = "";
        setText(newText);
    }


    const copyText = () => {
        const textSelector = document.getElementById("text-area")
        textSelector.select();
        navigator.clipboard.writeText(textSelector.value);
        // props.showAlert("Copied To Clipboard");
        setMyText("Copied!");
        setMyTextColor('success');

        setTimeout(() => {
            setMyText("Copy Text");
            setMyTextColor('primary');

        }, 1500);
    }

    const extraSpaceRemover = () => {
        let newText = text.split(/[ ]+/); //Learn REGEX js //
        setText(newText.join(" "));
    }

    return (
        <>
            <div className="container">
                <h1 id="main_heading" className='my-3'>{props.heading}</h1>

                <div className="mb-3">
                    <label htmlFor="Box" className="form-label">{props.label}</label>

                    <textarea style={{}} id='text-area' className="form-control" value={text} placeholder='Enter Your Text Here' rows="10" onChange={Onchange} ></textarea>

                </div>

                <div id="button_div" className='my-5'>
                    <button className={`btn btn${props.buttonMode}${myTextColor} my-btn`} onClick={copyText} >{myText}</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={upperCaseConverter} >Convert To Uppercase</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={lowerCaseConverter} >Convert To lowercase</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={capitalizeConverter} >Capitalize</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={boldConverter} >Bold</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={underlineConverter} >underline</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={extraSpaceRemover} >extraSpaceRemover</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={htmlparser} >parse html</button>
                    <button className={`btn btn${props.buttonMode}primary my-btn`} onClick={clear} >clear</button>
                </div>
            </div>

            {/* dark me outline aur light me simpple  */}

            <div className="container">

                <h2 className='my-3' >Text Summary</h2>
                <p className='my-1 scale-in-tl'>You have entered {text.length} characters</p>
                <p className='my-1 scale-in-tl'>You have entered {(text.split(/\s+/).length) - 1} words</p>
                <p className='my-1 scale-in-tl'>You will take {((text.split(" ").length) - 1) * 0.008} minutes to read it</p>
                {/* <p className='my-1'>{typingSpeed} WPM</p> */}

            </div>


            <footer>
                <h5 className='text-center my-5 py-5 heartbeat'>Made With 💗 by  <a href="https://github.com/MR-DHRUV" target="_blank" rel="noopener noreferrer"> Dhruv </a> </h5>
            </footer>

        </>
    )
}


TextForm.proptype = { label: PropTypes.string, heading: PropTypes.string }
TextForm.defaultProps = { label: null, heading: "Heading" }

// state is content in dom , like req.body ka data state haii
// bina page reload kare react state ke ander ka data udate kara skta haii
// state ek element ko diya jata haii uska data update krwane ke liye




