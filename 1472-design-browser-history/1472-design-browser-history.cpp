class BrowserHistory {
    
     private:
    stack<string> history; // Stack to store past pages
    stack<string> future;
public:
    
    
     BrowserHistory(string homepage) {
    visit(homepage);
  }

  // Adds a new page to the history and clears the future stack
  void visit(string url) {
    history.push(url);
    future = stack<string>(); // Clear the future stack
  }

  // Moves the user back a certain number of pages in the history
  string back(int steps) {
    while (history.size() > 1 && steps-- > 0)
      future.push(history.top()), history.pop(); // Move pages from history to future stack
    return history.top(); // Return the current page after navigation
  }

  // Moves the user forward a certain number of pages in the future
  string forward(int steps) {
    while (!future.empty() && steps-- > 0)
      history.push(future.top()), future.pop(); // Move pages from future to history stack
    return history.top(); // Return the current page after navigation
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */