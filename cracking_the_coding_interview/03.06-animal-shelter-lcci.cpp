/*
 * 带时间戳的队列与子队列
 *
 * 动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。允许使用Java内置的LinkedList数据结构。

enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。

dequeue*方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/animal-shelter-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class AnimalShelf {
public:
    AnimalShelf(): timestamp(0) {

    }
    
    void enqueue(vector<int> animal) {
        qs[animal[1]].push({timestamp++, animal});
    }
    
    vector<int> dequeueAny() {
        if (!qs[0].empty() && !qs[1].empty()) {
            int i = qs[0].front().first > qs[1].front().first;
            return dequeue_i(i);
        }
        if (!qs[0].empty()) return dequeueCat();
        if (!qs[1].empty()) return dequeueDog();
        return {-1, -1};
    }
    
    vector<int> dequeueDog() {
        return dequeue_i(1);
    }
    
    vector<int> dequeueCat() {
        return dequeue_i(0);
    }
private:
    vector<int> dequeue_i(int i) {
        if (qs[i].empty()) return {-1, -1};
        vector<int> v = std::move(qs[i].front().second); qs[i].pop();
        return v;
    }
    queue<pair<int, vector<int> > > qs[2];
    int timestamp;
};
