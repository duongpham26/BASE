package P2_5.CastingAndGenerics;

public class B3_Portfolio<T> {
	T[] data;

	public B3_Portfolio(int capacity) {
//		data = new T[capacity]; // illegal; compiler error
		data = (T[]) new Object[capacity]; // legal, but compiler warning
	}

	public T get(int index) {
		return data[index];
	}

	public void set(int index, T element) {
		data[index] = element;
	}

}
