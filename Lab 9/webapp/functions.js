function updateValues(){
    console.log("Button pressed!")
    var blueborder = document.getElementById("blueborder").value;
    var redborder = document.getElementById("redborder").value;
    var greenborder = document.getElementById("greenborder").value;
    var borderwidth = document.getElementById("borderwidth").value;
    var bluebackground = document.getElementById("bluebackground").value;
    var redbackground = document.getElementById("redbackground").value;
    var greenbackground = document.getElementById("greenbackground").value;

    var texttarget = document.getElementById("texttarget");
    texttarget.style.borderColor = `rgb(${redborder}, ${greenborder}, ${blueborder})`;
    texttarget.style.borderWidth = `${borderwidth}px`;
    texttarget.style.backgroundColor = `rgb(${redbackground}, ${greenbackground}, ${bluebackground})`;}

function comparePasswords(){
    var password1 = document.getElementById("password").value;
    var password2 = document.getElementById("confirmpassword").value;

    if (password1 == password2){
        if (password1.length < 8){
            alert("Password is too short!")
        }
        else if (password1.length >= 8){
            alert("This password works! Well done!")
        }
    }
    else{
        alert("The passwords do not match!")
    }
}

