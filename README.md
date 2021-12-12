# QuantcastCodingAssessment

Language: C++

Compile command: g++ -g -o most_active_cookie most_active_cookie.cc

I read each line of the file, and if the line contains the specified date, I increase the frequency count for that cookie, which is stored in a hashmap (key: cookie, value: frequency). I also keep track of the maximum frequency, and later print all the keys with maximum frequency. When reading the file, I had the idea to stop the loop when a date is encountered that is earlier than the date specified, because in the example, the dates are in the order of most recent to oldest. However, I was not sure if all the test cases would be in that order, so I did not do that.
