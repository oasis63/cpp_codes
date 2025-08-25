var inorderTraversal = function* (arr) {

    const flattenArr = input.flat(Infinity);

    for (let i = 0; i < flattenArr.length; i++) {
        yield flattenArr[i];
    }

};

const input = [1, [2, 3]];

const gen = inorderTraversal(input);
console.log(gen.next().value);
console.log(gen.next().value);
console.log(gen.next().value);



// const input = [1, [2, 3]];
// const flattenArr = input.flat(Infinity);
// console.log(flattenArr);
