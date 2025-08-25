console.log('test2')


var f1 = function () {
    this.mp = {};

};


f1.prototype.set = function (key, value, duration) {
    this.mp[key] = value;

    return true;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
f1.prototype.get = function (key) {
    return this.mp[key];
};

/** 
 * @return {number} count of non-expired keys
 */
f1.prototype.count = function () {

};


const obj = new f1()

console.log(obj.set(3, 4, 3));
