var bday = new Date('september 5, 2000');
var today = new Date();

bday.setYear = today.getFullYear;
daysAfter = (today.getTime() - bday.getTime()) / (1000*60*60*24);
daysAfter = Math.floor(daysAfter);
document.getElementById("result").innerHTML = daysAfter + "일";

var hundays = new Date();
hunday = bday.getTime() + (100*24*60*60*1000);
hundays.setTime(hunday);
document.getElementById("hundaysbef").innerHTML = hundays.toLocaleDateString();
document.getElementById("ndays").innerHTML = daysAfter + "일후";
document.getElementById("today").innerHTML = today.toLocaleDateString();