#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    while (true) {
        int lines;
        int max_tickets;
        
        cin >> lines >> max_tickets;
        
        if (lines == 0 && max_tickets == 0) break;
        
        int best_tickets = 0;
        int best_cost = 0;
        double best_avg_cost = 1.0 / 0.0;
        
        for (int i = 0; i < lines; i++) {
            int tickets;
            int cost;
            
            cin >> tickets >> cost;
            
            if (tickets > max_tickets) continue;
            
            double avg_cost = (double) cost / (double) tickets;
            // cout << avg_cost << endl;
            
            if (avg_cost < best_avg_cost || (avg_cost == best_avg_cost && tickets > best_tickets)) {
                best_avg_cost = avg_cost;
                best_tickets = tickets;
                best_cost = cost;
            }
        }
        
        if (best_avg_cost < (1.0 / 0.0)) {
	        cout << "Buy " << best_tickets << " tickets for $" << best_cost << endl;
        } else {
            cout << "No suitable tickets offered" << endl;
        }
    }
    
    return 0;
}