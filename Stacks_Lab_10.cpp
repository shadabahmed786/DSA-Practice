#include<iostream>
using namespace std;

#define n 100

class CustomerSupportCenter {
private:
    struct Request {
        int request_id;
        string user_Name;
        string issue_Description;

        // Constructor to initialize the request
        Request(int id = 0, string name = "", string description = "") 
            : request_id(id), user_Name(name), issue_Description(description) {}
    };

    struct GeneralSupportQueue {
        Request* arr;
        int front;
        int back;
    } generalSupportQueue;

    struct PrioritySupportStack {
        Request* arr;
        int top;
    } prioritySupportStack;

    Request processedRequests[n]; // Array to track processed requests
    int processedCount = 0; // Counter to keep track of processed requests

public:
    CustomerSupportCenter() {
        generalSupportQueue.arr = new Request[n];
        generalSupportQueue.front = -1;
        generalSupportQueue.back = -1;

        prioritySupportStack.arr = new Request[n];
        prioritySupportStack.top = -1;
    }

    // Method to enqueue a general support request
    void enqueueGeneralRequest(int request_id, string user_Name, string issue_Description) {
        if (generalSupportQueue.back == n - 1) {
            cout << "General Requests Exceed: Max Limit Reached" << endl;
            return;
        }
        generalSupportQueue.back++;
        generalSupportQueue.arr[generalSupportQueue.back] = Request(request_id, user_Name, issue_Description);

        if (generalSupportQueue.front == -1) {
            generalSupportQueue.front = 0;
        }
    }

    // Method to push a priority support request
    void pushPriorityRequest(int request_id, string user_Name, string issue_Description) {
        if (prioritySupportStack.top == n - 1) {
            cout << "Priority Requests Exceed: Max Limit Reached!" << endl;
            return;
        }
        prioritySupportStack.top++;
        prioritySupportStack.arr[prioritySupportStack.top] = Request(request_id, user_Name, issue_Description);
    }

    // Method to set processing ratio for general to priority requests
    void setProcessingRatio(int generalToPriorityRatio) {
        // For now, this can be used for custom processing logic in processRequest
    }

    // Method to process requests based on a general-to-priority ratio
    void processRequests(int generalToPriorityRatio) {
        int generalProcessed = 0;

        // Process requests while there are requests in either the general queue or priority stack
        while (generalSupportQueue.front <= generalSupportQueue.back || prioritySupportStack.top >= 0) {
            // Process general requests based on the ratio
            while (generalProcessed < generalToPriorityRatio && generalSupportQueue.front <= generalSupportQueue.back) {
                auto& req = generalSupportQueue.arr[generalSupportQueue.front];
                processedRequests[processedCount++] = Request(req.request_id, req.user_Name, req.issue_Description);
                generalSupportQueue.front++;
                generalProcessed++;
            }

            // Reset the counter and process one priority request if available
            generalProcessed = 0;
            if (prioritySupportStack.top >= 0) {
                auto& req = prioritySupportStack.arr[prioritySupportStack.top];
                processedRequests[processedCount++] = Request(req.request_id, req.user_Name, req.issue_Description);
                prioritySupportStack.top--;
            }
        }
    }

    // Method to display processed requests
    void displayProcessedRequests() {
        if (processedCount == 0) {
            cout << "No Requests Processed yet!" << endl;
            return;
        }

        cout << "Processed Requests:" << endl;
        for (int i = 0; i < processedCount; i++) {
            cout << "Request ID: " << processedRequests[i].request_id << endl;
            cout << "User Name: " << processedRequests[i].user_Name << endl;
            cout << "Issue Description: " << processedRequests[i].issue_Description << endl;
            cout << "----------------------------" << endl;
        }
    }
};

int main() {
    CustomerSupportCenter supportCenter;

    // Adding some general and priority requests
    supportCenter.enqueueGeneralRequest(1, "John Doe", "Account Issue");
    supportCenter.enqueueGeneralRequest(2, "Jane Smith", "Payment Query");
    supportCenter.pushPriorityRequest(3, "VIP User", "Security Breach");

    // Processing requests with a ratio of 1 general request to 1 priority request
    supportCenter.processRequests(1);

    // Displaying the processed requests
    supportCenter.displayProcessedRequests();

    return 0;
}
