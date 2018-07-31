/* Write a function deepEqual that takes two values and returns true only if they are the same value or are objects with the same properties, where the values of the properties are equal when compared with a recursive call to deepEqual.*/

// The Object.keys function will be useful when you need to go over
// the properties of objects to compare them.

function deepEqual(obja, objb) {
    // 先比较类型，如果不一致，返回false
    if ((typeof obja) !== (typeof objb)) {
        return false;
    } else {
        // 如果类型一致比较属性
        if ((typeof obja) === 'object' && (typeof objb) === 'object') {
            for (let key in obja) {
                // console.log(obja[key], objb[key]);
                // 这里需要递归比较属性的值
                if (!deepEqual(obja[key], objb[key])) {
                    return false;
                }
            }
            return true;
        } else {
            // 直接比较值 是否一致
            return obja === objb;
        }
    }
}

let obj = { here: { is: "an" }, object: 2 };
console.log(deepEqual(obj, obj));
// → true
console.log(deepEqual(obj, { here: 1, object: 2 }));
// → false
console.log(deepEqual(obj, { here: { is: "an" }, object: 2 }));
// → true
