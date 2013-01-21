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
 };
 
    document.getElementById('password').onkeydown = function(event){
      if (this.value.length === 0){
	return ((event.keyCode>=64 && event.keyCode<=90) || (event.keyCode>=97 && event.keyCode<=122));
      }
    } 
    
     document.getElementById('login_form').onsubmit = function(event){
      if (this.getElementById('user name').value.length === 0){
// 	    alert("no user name");
	    return false;
      }
      
      if (this.getElementById('password').value.length >= 4){
	alert("password must have 4 characters");
	return false;
      }
      
     }    
}
    
 

