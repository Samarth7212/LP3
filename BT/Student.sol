//SPDX-License-Identifier-MIT
pragma solidity ^0.8.0;

contract StudentData{

    struct Student{
        uint rollNumber;
        string name;
        string department;
    }

    Student[] student;
    mapping(uint => bool) students;

    
    event log(string _fun, address _sender, uint _val, bytes _data);

    function addStudent(uint rollNumber, string memory name, string memory department) public returns (string memory){
        require(students[rollNumber] == false, "Student Already Present");
        Student memory newStudent = Student({
            rollNumber:rollNumber,
            name : name,
            department : department
        });
        students[rollNumber] = true;
        student.push(newStudent);

        return "Student added successfully";
    }

    function getStudent(uint roll) public view returns (string memory, string memory){
        require(students[roll] == true, "Roll number not present");

        for(uint i = 0; i < student.length; i++){
            Student memory stud = student[i];
            if(stud.rollNumber == roll){
                return (stud.name, stud.department);
            }
        }

        return ("The student was fetched successfully", "");
    }

    function getStudentCount() public view returns(uint){
        return student.length;
    }
    fallback() external payable{
        emit log("fallback function", msg.sender, msg.value, msg.data);
    }
    receive() external payable{
       emit log("receive function", msg.sender, msg.value, "");
    }
    function checkBalance() public view returns(uint){
        return address(this).balance;
    }

}