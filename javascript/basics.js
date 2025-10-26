#!/usr/bin/env node
/*
    ^^^^^ this hashbang comment is the third and special
    type of comment in javascript which tells which javascript
    engine should execute the script.
*/


/*
    Javascript is case sensitive, not just that, variable
    variable names can have unicode characters.
    fruit != Fruit != Früit; <-- (semicolon at the end is optional)
*/
const Fruit = "apple";
const Früit = "apple";
const fruit = "apple";


/*
    var, let and const are variable declarators, const
    declaration requires initial value, others do not.
    let declared variables are block-scoped/local. var 
    declares a function or global scoped variable.

    variables or identifiers start with letters, '_'
    or '$' in javascript, rest characters can contain
    digits. unicode letters are allowed.
*/
var variabl; // defaults to undefined
let variabe; // defaults to undefined
const variale = "initial value";

/*
    there are three main scopes, global, module and function.
    block scope is another additional scope. var declared variables
    are hoisted to the top of function or global scope. functions are
    hoisted entirely i.e. can be called from anywhere in their scope.
*/


/*
QUESTION:
                console.log(x === undefined);
                var x = 3;

                (function () {
                  console.log(x);
                  var x = "local value";
                })();

    if the variable x is hoisted and a var x; declaration
    gets added to the top of this function, then why doesn't
    it print anything if i remove the `var x = "local value"`
    line from this function's body.
*/
