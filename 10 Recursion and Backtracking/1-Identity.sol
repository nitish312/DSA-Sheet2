// SPDX-License-Identifier: GPL-3.0

pragma solidity ^ 0.4.0;

contract Identity
{
    string name;
    uint age;

    constructor() public
    {
        name = "Beast";
        age = 20;
    }

    function getName() view public returns(string memory)
    {
        return name;
    }
    function getAge() view public returns(uint)
    {
        return age;
    }
}