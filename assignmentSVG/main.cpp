#include "AllocateStatistics.h"

void Run()
{
	// Load and generate the figure from this function

	// Memory should be automatically be deallocated
	// at the end of this function
}

int main()
{
	Run();

	// Stop memory tracking and write the graph file now
	alloc_tracker.StopTracking();
    alloc_tracker.DumpPeaks();
    alloc_tracker.WriteGraph();
    return 0;
}
