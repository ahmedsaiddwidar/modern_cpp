// //----------------------------------------------------------
// // JavaScript code snippets for React
// //----------------------------------------------------------

// // 1. Functional Component
// const MyComponent = () => {
//     return <div>Hello, World!</div>;
// };

// // 2. Class Component
// class MyComponent extends React.Component {
//     render() {
//         return <div>Hello, World!</div>;
//     }
// }

// // 3. useState Hook
// const MyComponent = () => {
//     const [count, setCount] = useState(0);
//     return (
//         <div>
//             <p>You clicked {count} times</p>
//             <button onClick={() => setCount(count + 1)}>Click me</button>
//         </div>
//     );
// };

// // 4. useEffect Hook
// const MyComponent = () => {
//     useEffect(() => {
//         // ComponentDidMount
//         return () => {
//             // ComponentWillUnmount
//         };
//     }, []);
//     return <div>Hello, World!</div>;
// };

// // 5. Context API
// const MyContext = createContext();
// const MyProvider = ({ children }) => {
//     const [value, setValue] = useState("Hello");
//     return <MyContext.Provider value={{ value, setValue }}>{children}</MyContext.Provider>;
// };

// // 6. PropTypes
// MyComponent.propTypes = {
//     title: PropTypes.string.isRequired,
//     onClick: PropTypes.func,
// };

// // 7. Default Props
// MyComponent.defaultProps = {
//     title: "Default Title",
// };

// // 8. Higher-Order Component
// const withExtraInfo = (WrappedComponent) => {
//     return (props) => {
//         return <WrappedComponent extraInfo="Some extra info" {...props} />;
//     };
// };

// // 9. Render Props
// const MyComponent = ({ render }) => {
//     return <div>{render("Hello, World!")}</div>;
// };

// // 10. Fragments
// const MyComponent = () => {
//     return (
//         <>
//             <h1>Hello</h1>
//             <h2>World</h2>
//         </>
//     );
// };


//----------------------------------------------------------


1- we don't use var anymore, we use const and let becuase they have block scope and prevent accidental re-declarations.

->const is used for variables that won't be reassigned, while let is used for variables that may be reassigned.
-> ex: const dataName = "data 2025";
-> es: let page = 1;  page = 2; is allowed with let but not with const.

***********************************************************************************************
***********************************************************************************************
***********************************************************************************************



2- Arrow Functions provide a concise syntax and lexically bind the this value.
the java style: function add(a, b) {
    return a + b;
}
the react style: const add = (a, b) => a + b{
    return a + b;
};
or the same sytax const add = (a, b) => a + b;

react component example:
const MyComponent = () => {
    return <div>Hello</div>;
    };

    const Button = () => (...)

***********************************************************************************************
***********************************************************************************************
***********************************************************************************************

3- rule of react: no return statement means nothing appears on the screen.

const MyComponent = () => {
  <div>Hello</div>;
};
nothing appears as there is no return statement, React renders the return, No return → blank screen

it should be like this: const MyComponent = () => <div>Hello</div>;(it has a return value but is is just short version)

***********************************************************************************************
***********************************************************************************************
***********************************************************************************************

4- objects & destructuring:
const dataset = {
    id: 1,
    name: "Dataset 2025",
    rows: 1000
};
to destructure it in react style:
const { id, name, rows} = dataset;

***********************************************************************************************
***********************************************************************************************
***********************************************************************************************

5- .map() is used to render lists in React.(the most important concept in React after components and props)
it as a special React-friendly loop.

.map() means:

“Go through the array
and for each item,
return something new”
.map() = loop + return

javascript style:
const numbers = [1, 2, 3];
numbers.map(*((n) => n *2))  //[2,4,6]

react style:
const tables = ["Table A", "Table B"];

tables.map((table) => {
  return <div>{table}</div>;
});

Read it slowly:

    Take "Table A" → return <div>Table A</div>

    Take "Table B" → return <div>Table B</div>

***********************************************************************************************
***********************************************************************************************
***********************************************************************************************

6- ternary operator is used for conditional rendering in React.
the javascript style:
if (isActive) {
  "Green";
} else {
  "Red";
}

the react style:
{isActive ? "Green" : "Red"}

example from matirail ui:
<Button color={isActive ? "primary" : "secondary"}>Click Me</Button>

const color = isActive ? "success" : "error";