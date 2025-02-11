const std = @import("std");
const sqrt = std.math.sqrt;
const bound: u32 = 1000000;

var primes = std.mem.zeroes([sqrt(bound) + 1]u32);

fn isprime(n: u32) bool {
    var i: u32 = 0;
    while (primes[i] > 0) : (i += 1)
        if (n % primes[i] == 0)
            return false;
    primes[i] = n;
    return true;
}

pub fn main() void {
    var prod: u32 = 1;
    var phi: u32 = 1;

    for (2..sqrt(bound)) |i| {
        if (isprime(@intCast(i))) {
            if (prod * i < bound) {
                prod *= @intCast(i);
                phi += 1;
            } else break;
        }
    }
    std.debug.print("{any} : {any}\n", .{ prod, phi });
}
