package lab1;

public class Bai1 {
	public static void main(String[] args) {
		int arr[] = {-2, 3, 4, -1, -3, 1, 2, -4, 0};
		int i = 0;
		int j = arr.length - 1;
		
		for(i = 0; i < arr.length - 1; i++) {
			for(j = i + 1; j < arr.length; j++) {
				if(arr[j] < arr[i]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		for(int k = 0 ; k < arr.length; k++ ) {
			System.out.print(arr[k] + " ");			
		}
	}
}
