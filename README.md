# Stack

### 스택
- 물건을 쌓아 올리듯 자료를 쌓아 올린 형태의 자료구조
- 선형구조
- 후입선출(LIFO) : 마지막에 삽입한 자료를 가장 먼저 꺼냄
- 자료구조 및 연산
  - top : 가장 마지막에 삽입된 원소의 위치
  - push : 자료를 저장
  - pop : 자료를 꺼냄(삽입한 자료의 역순)
  - isEmpty : 스택이 비어있는지 확인
  - peek : 스택의 top에 있는 item을 반환
- 배열을 사용하여 구현할 시 구현이 용이하다는 장점이 있지만, 크기를 변경하기 어려움
- 링크드 리스트를 활용하여 이를 해결

### 스택의 응용
- Function call
 - 프로그램에서 함수 호출과 복귀에 따른 수행 순서를 관리
 - 함수는 마지막에 호출된 함수를 먼저 실행 후 복귀하는 구조(LIFO)
 - 함수 호출 발생 시 **지역변수, 매개변수 및 수행 후 복귀할 주소** 등의 정보를 **스택 프레임**에 저장
 - 함수의 실행이 끝나면 시스템 스택을 pop하면서 프레임에 저장되어있던 **주소로 복귀**
 - Stack overflow : 메모리에 비해 많은 양을 저장하려 할 때 발생 ex)무한 재귀
  
### 재귀호출
- 자기 자신을 호출하여 순환 수행되는 구조
- 프로그램을 간단하게 작성할 수 있음

### DFS(깊이 우선 탐색)
- 비선형구조인 그래프 구조는 모든 자료를 빠짐없이 검색하는 것이 중요
- 시작 정점의 한 방향으로 갈 수 있는 경로가 있는 곳까지 깊이 탐색
- 더 이상 갈 곳이 없게 되면, 마지막에 만났던 갈림길이 있는 정점으로 되돌아와서 다른 방향의 정점으로 탐색을 계속 반복하여 모든 정점을 방문
- 마지막에 만났던 갈림길으로 되돌아가서 다시 깊이 우선 탐색을 반복해야 함으로 **후입선출** 구조의 **스택** 사용

#### 관련 문제
[1.Bracket](https://github.com/KimUJin3359/Stack/tree/master/Bracket)
- 괄호의 짝을 검사하는 프로그램
- 접근 방법
  - (, <이 나올 시 stack에 push
  - ), >이 나올 시 stack의 top 원소가 올바르게 매칭() -> (, > -> <)되는지 확인
    - 매칭이 맞게 되는지 비교 방법 : 배열을 만들어서 arr['('] = ')', arr['<'] = '>'을 입력
    - top의 원소가 arr[str[i]]와 같은지 비교
  - 올바르지 않다면 wrong, 올바르다면 계속해서 비교
  
[2.Bracket2](https://github.com/KimUJin3359/Stack/tree/master/Bracket2)
- 괄호의 갯수가 늘어난 Bracket 문제 (, <, [, {

[3.DFS](https://github.com/KimUJin3359/Stack/tree/master/DFS)
- 정점, 간선을 입력받아 깊이 우선 탐색을 하였을 때 방문하는 정점을 출력하는 문제

[4.DFS_iterative](https://github.com/KimUJin3359/Stack/tree/master/DFS_iterative)
- 3번을 iterative하게 구현하는 문제

[5.FindRoad](https://github.com/KimUJin3359/Stack/tree/master/FindRoad)
- A도시에서 출발하여 B도시로 가는 길이 존재하는지 조사
- 길 중간 중간에는 최대 2개의 갈림길이 존재하고, 모든 길은 일방통행으로 되돌아 오는 것이 불가능
- A와 B는 숫자 0과 99로 고정
- 접근 방법
  - DFS를 사용하여 모든 경우의 수를 확인
  - 시간 줄이기
    - 99에 도착하는 경우가 있을 경우 flag를 1로 설정하여 가지치기
    - 간선을 입력받을 때 99로 향하는 간선이 없을 경우 return

[6.Maze](https://github.com/KimUJin3359/Stack/tree/master/Maze)
- 16*16 행렬로 만들어진 미로가 존재
- 좌상단을 (0,0), 가로방향을 x 방향, 세로방향을 y 방향이라고 할 때, 미로의 도착점은 (13,13)
- 갈 수 있는 길(0), 벽(1), 출발점(2), 도착점(3)
- 접근 방법
  - delta x, y를 사용하여 DFS로 해결

[7.Print](https://github.com/KimUJin3359/Stack/tree/master/Print)
- 스택 구현 문제

[8.Pow](https://github.com/KimUJin3359/Stack/tree/master/pow)
- pow 구현 문제

[9.Selection_sort](https://github.com/KimUJin3359/Stack/tree/master/Selection_sort)
- selection sort 구현 문제

//
### Memoization
- 피보나치 수 등 반복된 작업을 할 때, 중복 호출이 일어나는 것을 해소
- 프로그램을 실행하 ㄹ때 이전에 계산한 값을 메모리에 저장해서 매번 다시 계산하지 않도록 하여 실행속도를 빠르게 하는 기술
- 동적 계획법의 핵심

### DP(Dynamic Programming)
- 최적화 문제를 해결하는 알고리즘
- 입력 크기가 작은 부분 문제들을 모두 해결한 후에 그 해들을 이용하여 보다 큰 크기의 부분 문제들을 해결

