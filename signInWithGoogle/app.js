

  // Import the functions you need from the SDKs you need

  import { initializeApp } from "https://www.gstatic.com/firebasejs/9.9.2/firebase-app.js";
  import { getAuth , GoogleAuthProvider , signInWithPopup} from "https://www.gstatic.com/firebasejs/9.9.2/firebase-auth.js";


  // Your web app's Firebase configuration

  const firebaseConfig = {

    apiKey: "AIzaSyBbXn11EFZ-B4UutkGbbvFFhddnqWFpDWc",

    authDomain: "test-app-c0aed.firebaseapp.com",

    projectId: "test-app-c0aed",

    storageBucket: "test-app-c0aed.appspot.com",

    messagingSenderId: "797893271922",

    appId: "1:797893271922:web:5fc8bade62add0ca573deb"

  };


  // Initialize Firebase

  const app = initializeApp(firebaseConfig);

  const auth = getAuth();
  const provider = new GoogleAuthProvider();

  document.getElementById("login").addEventListener("click", function() {
    signInWithPopup(auth, provider)
  .then((result) => {
    const user = result.user;
    console.log(user);
    // ...
  }).catch((error) => {
    console.log(error);
  });
  })



  