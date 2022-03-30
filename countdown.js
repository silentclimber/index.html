// var end1 = new Date("Mar 31, 2022 22:00:00");
var end1 = new Date("31 March 2022 10:00 PM");
document.getElementById('enddate').innerText = end1;

const inputs = document.querySelectorAll("input")

function clock() {
    const end = new Date(end1)
    const now = new Date()
    const diff = (end - now);
    inputs[0].value = Math.floor(diff / (1000 * 60 * 60 * 24));
    inputs[1].value =  Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    inputs[2].value = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
    inputs[3].value = Math.floor((diff % (1000 * 60)) / 1000);
}
clock();

setInterval(
    function(){
        clock()
    },
    1000
)

//new Date(year, month, day, hours, minutes, seconds, milliseconds)

// Set the date we're counting down to
var countDownDate = new Date("Mar 31, 2022 22:00:00").getTime();
// Update the count down every 1 second
var x = setInterval(function() {

  // Get today's date and time
  var now = new Date().getTime();
    
  // Find the distance between now and the count down date
  var distance = countDownDate - now;
    
  // Time calculations for days, hours, minutes and seconds
  var days = Math.floor(distance / (1000 * 60 * 60 * 24));
  var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
  var seconds = Math.floor((distance % (1000 * 60)) / 1000);
    
  // Output the result in an element with id="secondcount"
  document.getElementById("secondcount").innerHTML = days + "d " + hours + "h "
  + minutes + "m " + seconds + "s ";

  // If the count down is over, write some text 
  if (distance < 0) {
    clearInterval(x);
    document.getElementById("secondcount").innerHTML = "EXPIRED";
  }
}, 1000);