import java.util.Scanner;
import java.util.*;
import java.io.*;

class  UpsAndDowns {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int arr[] = new int[n];
    for(int i=0;i<n;i++) {
      arr[i] = sc.nextInt();
    }
    for(int i=0;i<=n-2;i++) {
      if(i%2==0) {
        if(arr[i]<=arr[i+1]) {
          continue;
        }
        else{
          int temp = arr[i];
          arr[i]=arr[i+1];
          arr[i+1]= temp;
        }
      }
      else{
        if(arr[i]>=arr[i+1]) {
          continue;
        }
        else{
          int temp = arr[i];
          arr[i]=arr[i+1];
          arr[i+1]= temp;
        }
      }
    }
    for(int i=0;i<n;i++){
      System.out.print(arr[i]+" ");
    }
  }
}
