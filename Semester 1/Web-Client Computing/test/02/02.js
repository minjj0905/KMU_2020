var random_num = Math.floor(Math.random() * 44) + 1;
var cnt = 0;

function get_answer() {
    var num = document.getElementById("in").value;
    var result = document.getElementById("result")
    if (num == random_num) {
        result.innerHTML = "정답입니다!";
    }
    else if (num < random_num) {
        result.innerHTML = "UP!";
    }
    else if (num > random_num) {
        result.innerHTML = "DOWN!";
    }
    cnt++;
    document.getElementById("num").innerHTML = "시도 횟수 : " + cnt + "회";
}

function get_enter() {
    if (event.keyCode == 13) {
        get_answer();
    }
}

function reset() {
    document.getElementById("in").value = "";
    document.getElementById("result").innerHTML = "";
    cnt = 0;
    document.getElementById("num").innerHTML = "";

}