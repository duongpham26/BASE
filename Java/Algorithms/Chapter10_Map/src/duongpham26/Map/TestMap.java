package duongpham26.Map;

import java.util.HashMap;
import java.util.Map;

public class TestMap {
	public static void main(String[] args) {
		Map<Integer, String> map = new HashMap<>();

		System.out.println("isempty : " + map.isEmpty());
		map.put(2, "A");
		map.put(3, "C");
		map.put(4, "D");
		System.out.println(map.entrySet());

	}
}
