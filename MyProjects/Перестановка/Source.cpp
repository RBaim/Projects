#include<cstdio>
#include<cstdlib>

int askNumberOfElements()
{
	int ret;
	do
	{
		printf("Vvedite k-vo elementov v masive: ");
		scanf_s("%d", &ret);
	} while (ret <= 0);
	return ret;
}
int* packArray(int elements)
{
	int* ret = (int*)malloc(elements * sizeof(int));
	for (int i = elements; i; --i)
	{
		printf("Vvedite %d element massiva: ", elements - i + 1);
		scanf_s("%d", ret + elements - i);
	}
	return ret;
}

bool isContain(int* array, int countOfElements, int requiredElement)
//функция поиска элемента в массиве
{
	for (int i = 0; i < countOfElements; ++i)
		if (array[i] == requiredElement)
			return true;
	return false;
}
void nextElement(int* usedElements, int countOfUsedElements, int& currentElement)
//функция перехода к следующему элементу.
{
	while (isContain(usedElements, countOfUsedElements, ++currentElement)) {}
}
int firstElement(int* usedElements, int countOfUsedElements)
//Определяет, с какого элемента нацинать итерирование цикла.
{
	int currentElement = 0;
	while (isContain(usedElements, countOfUsedElements, currentElement))
		++currentElement;

	return currentElement;
}
void recursionPrintAllCombinationOfElemens(int* array, int elements, int countOfUsedElements = 0)
{
	/*
	вообще алгоритм мой тупорыл и состоит в следующем: заводится массив usedElements куда
	записывается номер элемента, который уже был включён в собираемый порядок следования.
	она объявлен как static, это значит что объявлен он будет только первый раз а не при
	каждом рекурсивном вызове функции. Далее если колличество записанных в массив использованных
	элементов не равно количеству элементов выводимого масива то входим в цикл по перебору
	всех неиспользованных элементов, каждый записывается в массив использованных элементов,
	после этого для него вызывается рекурсия.
	если число элементов в массиве использованных элементов равно числу элементов выводимого
	масива, т. е. достиднуто дно рекурсии(или пик, как привычнее) то вызывается цикл по
	выводу элементов исходного массива в соответствии с порядком, указанным в массиве использованных
	элементов. Если ваш препод - толстый троль, он может обратить внимание на то что вывод
	происходит не на этапе выхода из рекурсии а в отдельном цикле. Скажите ему что это вызвано
	спецификой моего алгоритма. и вообще если такой вопрос возникнет, знайте что вопрос этот
	сам по себе тупой, так как для реализации вывода на этапе выхода из рекурсии необходимо,
	так или иначе, вывести все собранные на верхних этажаэ элементы, а для этго всёравно
	нужен отдельный цикл.
	Недостаток алгоритма в том, что заводится дополнительный массив и по нему постоянно идёт
	пойск. Для учебной задачи такой недостаток не так уж и ужасен и кроме того, я пробовал
	гуглить на эту тему и альтернативных решений не нашел. вообще задача решается наилучшим
	образом не с помощью рекурсии а используя циклический подход. что, в целом, логично.

	Реализовано всё на чистом си, единственное - не уверен по поводу static. если его ваш
	препод не вытерпет(в нём нет ничего плохого, просто он может выходить за рамки преподаваемого
	материалла) то вынисите объявление usedElements или в глобальное пространство или в main
	*/
	static int* usedElements = (int*)malloc(elements * sizeof(int));
	if (countOfUsedElements != elements)
		for (int i = firstElement(usedElements, countOfUsedElements); i < elements; nextElement(usedElements, countOfUsedElements, i))
		{
			usedElements[countOfUsedElements] = i;
			recursionPrintAllCombinationOfElemens(array, elements, countOfUsedElements + 1);
		}
	else
	{
		for (int i = 0; i < elements; ++i)
			printf("%d\t", array[usedElements[i]]);
		printf("\n");
	}
}

void main()
{
	int n = askNumberOfElements(),
		*m = packArray(n);

	printf("Vse vozmojnie kombinacii elementov:\n");
	recursionPrintAllCombinationOfElemens(m, n);

	free(m);
	system("pause");
}