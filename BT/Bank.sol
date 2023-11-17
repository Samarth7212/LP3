//SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract Bank{
    mapping(address => uint) public user_account;
    mapping(address => bool) public user_exists;

    function create_account() public payable returns (string memory){
        require(user_exists[msg.sender] == false, "Account already created");
        if(msg.value == 0){
            user_account[msg.sender] = 0;
            user_exists[msg.sender] = true;
            return "Account Created";
        }

        require(user_exists[msg.sender] == false, "Account already created");
        user_account[msg.sender] = msg.value;
        user_exists[msg.sender] = true;
      

        return "Account Created";
    }

    function deposit(uint amount) public returns (string memory){
        require(user_exists[msg.sender] == true, "Account not created");
        require(amount > 0, "value for deposit is Zero");
        user_account[msg.sender] = user_account[msg.sender] + amount;
        return "Deposited Successfully";
    }
    function transfer(address payable userAddress, uint amount) public returns(string memory){
        require(user_account[msg.sender] > amount, "Insufficient Balance");
        require(user_exists[msg.sender] == true, "Account not created");
        require(user_exists[userAddress] == true, "Account not created");
        require(amount > 0, "Amount should be greater than 0");
        user_account[msg.sender] = user_account[msg.sender] - amount;
        user_account[userAddress] = user_account[userAddress] + amount;
        return "Transfered Successfully";
    }

    function withdraw(uint amount) public returns (string memory){
        require(user_exists[msg.sender] == true, "Cannot withdraw");
        require(amount > 0, "Value given is less than zero");
        require(amount < user_account[msg.sender], "Insuffient balance");
        user_account[msg.sender] = user_account[msg.sender] - amount;
        return "Withdrawn successfully";
    }
    function user_balance() public view returns(uint){
        return user_account[msg.sender];
    }


}