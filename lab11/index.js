window.onload = function() {
 
    //only numbers in user field
    document.getElementById('user_name').onkeydown = function(event){
    return (!(event.keyCode>=48 && event.keyCode<=57))  
//       {  
//       alert("ok");  
//       return true;
//       }  
//     else  
//      {  
//      alert("numbers arn't allowed");
//      event.preventDefault();
//      return false;  
//      }
 }
    //ensure the first character of password is a letter
    document.getElementById('password').onkeydown = function(event){
      if (this.value.length === 0){
	return ((event.keyCode>=64 && event.keyCode<=90) || (event.keyCode>=97 && event.keyCode<=122));
      }
    }
    
      //ensure that upon submission
     document.getElementById('login_form').onsubmit = function(event){
	//user name isn't empty

      if (document.getElementById('user_name').value.length === 0){
// 	    alert("no user name");
	    return false;
      }

      
// 	//ensure password is at least 4 characters long
      if (document.getElementById('password').value.length < 4){
	    alert("password must have 4 characters");
	    return false;
      }

     
      document.getElementById('paragraph').innerHTML = "you are now logged in as " + document.getElementById('user_name').value;

      // don't actually submit the form
      return false;
     }
}

function showHint(str)
{
	var xmlhttp;	
        if (str.length === 0) {
            document.getElementById("txtHint").innerHTML = "";
            return;
        }
        if (window.XMLHttpRequest){ // IE7+,Firefox,Chrome,Opera, Safari
            xmlhttp = new XMLHttpRequest();
        }
        else{ // code for IE6, IE5
            xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
        }
        xmlhttp.onreadystatechange = function() {
            if (xmlhttp.readyState == 4 && xmlhttp.status === 200){
                document.getElementById("txtHint").innerHTML = xmlhttp.responseText;
            }
        }
        xmlhttp.open("GET","http://www.cs.bgu.ac.il/~galrogo/suggest.php?q="+str, true);
        xmlhttp.send();
}