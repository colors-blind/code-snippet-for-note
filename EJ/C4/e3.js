// Objects, as generic blobs of values, can be used to build all sorts of data structures. 
// A common data structure is the list (not to be confused with array). 
// A list is a nested set of objects, with the first object holding a reference to the second, the second to the third, and so on.

// Also write a recursive version of nth.
// Like a lined list

function arrayToList(array) {
    let length = array.length;
    if (length === 0) {
        return null;
    }
    let node = {'value': array[length - 1], 'rest': null};
    let head = node;

    for (let i = length - 2; i >= 0; i--) {
        node = {'value': array[i], 'rest': node};
        head = node;
    }
    return head;
}

function listToArray(list) {
    let array = [];
    if (list === null) {
        return array;
    }
    let head = list;
    while (head != null) {
        array.push(head['value']);
        head = head['rest'];
    }
    return array;
}

function prepend(value, list) {
    if (list === null) {
        return {'value': value, 'rest': null};
    }
    return {'value': value, 'rest': list};
}

function nth1(list, index) {
    if (list === null) {
        return null;
    }
    let array = listToArray(list);
    let length = array.length;
    return length >= index ? array[index - 1] : null;
}

function nth2(list, index) {
    let count = 1;
    let head = list;
    while (head != null) {
        if (count === index) {
            return head['value'];
        } else if (count > index) {
            return null;
        }
        count += 1;
        head = head['rest'];
    }
    return null;
}

function recursive_nth(list, index) {
    if (index <= 0 || list === null) {
        return null;
    } else if (index === 1) {
        return list['value'];
    }
    return recursive_nth(list['rest'], index - 1);
}


let list = arrayToList([10, 20, 30, 40, 50]);
console.log(JSON.stringify(list, null, 4));
console.log(listToArray(list));

let new_list = prepend(90, prepend(60, list));
console.log(JSON.stringify(new_list, null, 4));
console.log(nth1(new_list, 1));
console.log(nth1(new_list, 2));
console.log(nth1(new_list, 10));

console.log('-------------');

console.log(nth2(new_list, 1));
console.log(nth2(new_list, 2));
console.log(nth2(new_list, 10));

console.log('-------------');

console.log(recursive_nth(new_list, 4));
console.log(recursive_nth(arrayToList([10, 20, 30]), 1));
