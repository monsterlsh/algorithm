�鲢���� �� ���� ����Ľ�� 
�����ģΪn 
���Խ��� by using insertion sort within merge sort when subproblems become sufficiently small. 
Consider a modification to merge sort in which n/k sublists of length k are sorted using insertion sort
 and then merged using the standard merging mechanism, where k is a value to be determined.

insetion sort  is O(n*k)
sublist of length k is O(n*log(n/k))  <-- T(a) = a*k*log(a)
the most value of k is   k=lg(n)  and  ��(nlgn+nlgnlgn)=��(nlgn)