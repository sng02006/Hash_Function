# Hash_Function
---------------
## 개요
------
49명의 학번을 크기가 49인 hash table에 모두 채워넣는 프로그램입니다.

## hash function design & collision resolution
----------------------------------------------
- hash function design
hashft1이 반환해주는 값을 result라고 정의합니다. result = students_id % 1000으로 모든 key 값이 가지고 있는 맨 앞자리의 4와 모두 같지는 않지만 여러 개의 key 값이 공통된 숫자를 가지는 2~5번째 숫자까지 없애고 뒤의 3자리 숫자만 남기기 위해서 mod 1000을 했습니다. 그 결과로 result = result % (last + 1)을 해서 0~last의 result 값을 반환해줍니다.

- collision resolution
collision이 발생했을 때, chaining과 open addressing 중 open addressing을 선택했고, open addressing의 double hashing을 사용했습니다. chaining을 쓰지 않은 이유는 추가적인 memory를 소모하고 search 할 때 선형 조사를 하게 되기 때문입니다. double hashing을 사용한 이유는 선형 조사를 하게 되는 경우 address가 1씩 증가하기 때문에 같은 address 근처에 대해 여러 개의 element가 집중되는 1차 군집이 발생합니다. 그래서 collision이 많이 발생하게 되므로 efficiency가 감소합니다. 이것을 조금 더 보완하기 위해 이차원 조사를 사용하게 되면 2차 군집이 발생하여 결국 선형 조사처럼 collision이 많이 발생하기 때문에 이를 보완한 double hashing을 사용했습니다.
따라서 collision function은 result를 반환하고 hashft1과 hashft2를 포함한 result = (hashft1(students_id, last) + j * hashft2(students_id, last) + j) % (last + 1)로 정의합니다. collision이 발생했을 때, hashft1값을 hashft2에 collision 횟수를 곱한 값을 더합니다. 이렇게 되면 hashft1이 같은 값을 가지더라도 hashft2가 달라서 군집이 생길 가능성이 감소합니다. 또한, hashft2가 NUM_STUDENTS의 약수이면 계속 일정한 값들만 나오기 때문에 open address를 찾아가지 못하는 현상이 발생합니다. 이러한 이유로 j를 더해서 last + 1로 mod 했습니다. 이런 현상을 방지하기 위한 또 다른 방법으로 hashft2가 NUM_STUDENTS의 약수이면 hashft2에 1을 더해서 약수가 아니게 할 수 있습니다. 하지만 만약 NUM_STUDENTS가 변하면, hashft2가 NUM_STUDENTS의 약수가 되는 경우가 많아질 수 있어서 첫 번째 방법을 사용했습니다.
hashft2가 반환해주는 값을 result로 정의합니다. result = (students_id % div) + 1로 정의하면서 result 값이 1~div가 되도록 합니다. 만약 1을 더해주지 않아서 result 값이 0이 되면 hashft1에 의한 값에서 계속 0을 더하는 것이 되면서 error가 발생합니다. 이때 cluster의 발생률을 줄이기 위해 div는 NUM_STUDENTS보다 작은 prime number로 설정합니다.

## hash table size & conflict
-----------------------------
- hash table size는 best hash table size인 49개입니다. 
- conflict는 총 69번 발생합니다.