// Approaches
// (Also explained in the code)

// The class RandomizedSet uses a vector v to store the elements and an unordered map mp to store the mapping of elements to their indices in the vector.
// The search function checks if a given value is present in the set by looking it up in the unordered map.
// The insert function adds a value to the set if it's not already present. It appends the value to the vector and updates the unordered map with its index.
// The remove function removes a value from the set if it's present. It replaces the value with the last element in the vector, updates the index in the unordered map, and then removes the last element.
// The getRandom function returns a random element from the vector using the rand() function.
// Complexity
// Time complexity:
// O(1)

// Space complexity:
// O(n)

class RandomizedSet {
    constructor() {
        this.list = [];
        this.map = new Map();
    }

    search(val) {
        return this.map.has(val);
    }

    insert(val) {
        if (this.search(val)) return false;

        this.list.push(val);
        this.map.set(val, this.list.length - 1);
        return true;
    }

    remove(val) {
        if (!this.search(val)) return false;

        const index = this.map.get(val);
        this.list[index] = this.list[this.list.length - 1];
        this.map.set(this.list[index], index);
        this.list.pop();
        this.map.delete(val);
        return true;
    }

    getRandom() {
        const randomIndex = Math.floor(Math.random() * this.list.length);
        return this.list[randomIndex];
    }
}

