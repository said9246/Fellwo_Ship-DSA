var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const exists = this.cache.has(key) && this.cache.get(key).expiry > Date.now();

    if (this.cache.has(key)) {
        clearTimeout(this.cache.get(key).timer);
    }

    const expiry = Date.now() + duration;

    const timer = setTimeout(() => {
        this.cache.delete(key);
    }, duration);

    this.cache.set(key, {
        value: value,
        expiry: expiry,
        timer: timer
    });

    return exists;
};

/** 
 * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {
    if (!this.cache.has(key)) return -1;

    const item = this.cache.get(key);

    if (item.expiry <= Date.now()) {
        this.cache.delete(key);
        return -1;
    }

    return item.value;
};

/**
 * @return {number}
 */
TimeLimitedCache.prototype.count = function() {
    let count = 0;

    for (const [key, item] of this.cache) {
        if (item.expiry > Date.now()) {
            count++;
        } else {
            this.cache.delete(key);
        }
    }

    return count;
};