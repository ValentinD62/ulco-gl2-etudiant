
function mul2(n) {
    return n*2;
}

function make_handler(parent, input){
    return function(){
        span = parent.getElementsByTagName('span')[0];
        span.innerHTML = mul2(input.value);
    }
}