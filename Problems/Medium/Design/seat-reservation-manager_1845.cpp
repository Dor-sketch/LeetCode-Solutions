/*
https://leetcode.com/problems/seat-reservation-manager/submissions/1092735292?envType=daily-question&envId=2023-11-06

Runtime Details 291ms
Beats 81.78%of users with C++
Memory Details 146.96MB
Beats 90.82%of users with C++
*/

class SeatManager {
  public:
    SeatManager(int n) {

        std::vector<uint32_t> seats(n);
        std::iota(seats.begin(), seats.end(),
                  1); // Fills the vector with 1, 2, ... n

        // Build the priority queue using the range constructor
        free_que_ = std::priority_queue<uint32_t, std::vector<uint32_t>,
                                        std::greater<uint32_t>>(seats.begin(),
                                                                seats.end());
    }

    int reserve() {
        auto top = free_que_.top();
        free_que_.pop();
        return top;
    }

    void unreserve(int seatNumber) { free_que_.push(seatNumber); }

  private:
    std::priority_queue<uint32_t, std::vector<uint32_t>, std::greater<uint32_t>>
        free_que_;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */