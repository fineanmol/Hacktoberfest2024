import 'dart:convert';

import 'package:dio/dio.dart';
import 'package:flutter/material.dart';
import 'package:flutter/rendering.dart';

class UserList extends StatefulWidget {
  UserList({Key? key}) : super(key: key);

  @override
  _UserListState createState() => _UserListState();
}

class _UserListState extends State<UserList> {
  int pageCount = 0;
  int pageNo = 1;
  List usersList = [];
  List<GestureDetector> page = [];
  bool isLoading = true;
  String url = 'https://reqres.in/api/users?page=1';
  loadUser() async {
    try {
      var dio = Dio();
      final response = await dio.get(url);
      if (response.statusCode == 200) {
        pageNo = response.data['page'];
        pageCount = response.data['total_pages'];
        usersList = response.data['data'];
        for (int i = 1; i <= pageCount; i++) {
          page.add(GestureDetector(
            onTap: () {
              setState(() {
                isLoading = true;
                url = 'https://reqres.in/api/users?page=$i}';
                page.clear();
              });
              loadUser();
            },
            child: Container(
              margin: EdgeInsets.symmetric(horizontal: 8, vertical: 15),
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(30),
                color: (i) == pageNo ? Colors.blueAccent : Colors.orangeAccent,
              ),
              child: Center(
                  child: Text(
                'Page ${i}',
                style: TextStyle(
                    color: (i) == pageNo ? Colors.black : Colors.white),
              )),
              padding: EdgeInsets.symmetric(horizontal: 20),
            ),
          ));
        }
        setState(() {
          isLoading = false;
        });
      } else {
        print('Please Check your Connection');
      }
    } catch (e) {
      print(e);
    }
  }

  @override
  void initState() {
    // TODO: implement initState
    loadUser();
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('User List'),
      ),
      body: isLoading
          ? Container(
              child: Center(child: CircularProgressIndicator()),
            )
          : Container(
              margin: EdgeInsets.symmetric(horizontal: 20, vertical: 8),
              child: Column(
                children: [
                  Expanded(
                      flex: 1,
                      child: ListView(
                        scrollDirection: Axis.horizontal,
                        children: page,
                      )),
                  Expanded(
                    flex: 8,
                    child: ListView.builder(
                        itemCount: usersList.length,
                        itemBuilder: (context, index) {
                          return Container(
                            margin: EdgeInsets.symmetric(vertical: 8),
                            padding: EdgeInsets.symmetric(
                                vertical: 18, horizontal: 18),
                            decoration: BoxDecoration(
                              color: Colors.black,
                              borderRadius: BorderRadius.circular(30),
                            ),
                            child: Column(
                              children: [
                                Row(
                                  children: [
                                    Image.network(usersList[index]['avatar']),
                                    SizedBox(width: 50),
                                    Column(
                                      children: [
                                        Text(
                                          usersList[index]['first_name'] +
                                              ' ' +
                                              usersList[index]['last_name'],
                                          style: TextStyle(color: Colors.white),
                                        ),
                                        SizedBox(height: 20),
                                        Text(
                                          usersList[index]['email'],
                                          style: TextStyle(color: Colors.white),
                                        ),
                                      ],
                                    ),
                                  ],
                                ),
                              ],
                            ),
                          );
                        }),
                  ),
                ],
              ),
            ),
    );
  }
}
