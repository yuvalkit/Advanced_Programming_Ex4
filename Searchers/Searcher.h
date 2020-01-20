
#ifndef ADVANCED_PROGRAMMING_EX4_SEARCHER_H
#define ADVANCED_PROGRAMMING_EX4_SEARCHER_H

#include "../Searchables/Searchable.h"
#include "../Components/State.h"

using namespace std;

/**
 * Searcher interface
 */
template <class T>
class Searcher {
protected:
    int nodesEvaluated;
public:
    virtual vector<State<T>*> search(Searchable<T>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual Searcher<T>* getClone() = 0;
    virtual ~Searcher() {}
};


#endif //ADVANCED_PROGRAMMING_EX4_SEARCHER_H
