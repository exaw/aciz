
#include <memory>
#include <vector>

#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>
#include <tbb/task_scheduler_init.h>

#include "circle.h"

using namespace Aciz;
using namespace tbb;
using namespace std;


double GetRadiiSumParallel (const vector<shared_ptr<Circle>> &circles)
{
    using namespace std;
    task_scheduler_init ( task_scheduler_init::automatic );
    double sum = parallel_reduce ( blocked_range<size_t> (0, circles.size ()), 0.0,
        [&circles] ( const blocked_range<size_t>& r, double s) -> double
        {
            for (size_t i = r.begin (); i != r.end (); ++i)
                s += circles[i]->GetR ();
            return s;
        },
        std::plus<double> ()
    );

    return sum;
}