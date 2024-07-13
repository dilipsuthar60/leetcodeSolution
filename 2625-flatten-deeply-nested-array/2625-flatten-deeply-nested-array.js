/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
function flatten(arr,n){
    if(n==0){
        return arr;
    }
    let output = [];
    for(let item of arr){
        if(Array.isArray(item)&&n>0){
            let value = flatten(item,n-1);
            output.push(...value);
        }
        else{
            output.push(item);
        }
    }
    return output
}
var flat = function (arr, n) {
    return flatten(arr,n);
};