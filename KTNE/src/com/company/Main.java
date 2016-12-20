package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    Scanner reader = new Scanner(System.in);
        ArrayList<String> words = new ArrayList<>();
        while (!reader.next().equals("write")){
            words.add(reader.next());
            System.out.println(words);
        }
        words.add("writes");

        ArrayList<String> substrings = new ArrayList<>();
        for (int i = 0; i < words.size(); i++){
            System.out.println(words.get(i));
            substrings.add(words.get(i).substring(4,5));
        }
        Collections.sort(substrings);

        System.out.println(substrings);
    }
}
