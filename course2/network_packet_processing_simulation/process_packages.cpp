#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}
    

    Response Process(const Request &request) 
    {
        bool dropped = false;
        int start_time = 0;
        
        // For processing current request, we only consider packets
        // that will not finish processing until after this request arrives.
        while (!finish_time_.empty() && request.arrival_time >= finish_time_.front()) {
            finish_time_.pop();
        }
        
        // Packets are dropped if the buffer is full
        if (finish_time_.size() == size_) {
            dropped = true;
            start_time = -1;
        } else {
            // Processing begins immediately after the last packet is processed
            start_time = finish_time_.empty() ? request.arrival_time : finish_time_.back();
            finish_time_.push(start_time + request.process_time);
        }
    
        return  *(new Response {dropped, start_time});
    }
private:
    int size_;
    queue <int> finish_time_;
};

vector <Request> ReadRequests() {
    vector <Request> requests;
    int count;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

vector <Response> ProcessRequests(const vector <Request> &requests, Buffer *buffer) {
    vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        cout << (responses[i].dropped ? -1 : responses[i].start_time) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int size;
    cin >> size;
    vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}