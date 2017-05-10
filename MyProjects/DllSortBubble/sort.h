#ifndef SORT_H_
#define SORT_H_


#ifdef BUBBLESORT_DLL_EXPORT
#define BUBBLESORT_API extern "C" _declspec(dllexport)
#else
#define BUBBLESORT_API extern "C" _declspec(dllimport)
#endif
BUBBLESORT_API void SortBubble(int *array, int size);

#endif
