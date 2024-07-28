### Chapter 1: Solution of Nonlinear Equations
- 1.1 Introduction
- 1.2 Types of Equations
- 1.3 Errors in Computing
- 1.4 The Bisection Method
- 1.5 The Method of False Position
- 1.6 Newton- Raphson Method
- 1.7 Solution of System of Nonlinear Equation
- 1.8 Fixed Point Iteration and Convergence


### 1.1 Introduction

#### Introduction

Nonlinear equations involve variables that are not just to the first power. These equations can include terms like \(x^2\), \(e^x\), \(\sin(x)\), and other more complex expressions. Because of this, the solutions to nonlinear equations can be more complicated and interesting compared to linear equations.


#### Solution of Nonlinear Equations in IT

Nonlinear equations are prevalent in Information Technology (IT) to model and solve various complex problems.

#### 1. Network Traffic Optimization

In IT, managing network traffic often involves nonlinear equations because the relationship between traffic load (number of packets sent) and network delay (time it takes for a packet to travel from source to destination) is not linear.

#### 2. Machine Learning: Logistic Regression

In machine learning, logistic regression is used for binary classification problems. The logistic function (sigmoid function) models the probability that a given input belongs to a particular class.

#### 3. Computer Graphics: Bezier Curves

Bezier curves are used in computer graphics for modeling smooth curves. The equation of a cubic Bezier curve is nonlinear.

#### 4. Cryptography: RSA Algorithm

In cryptography, the RSA algorithm involves solving nonlinear equations for encryption and decryption.

#### 5. Database Query Optimization

In databases, query optimization involves finding the best execution plan for a query. The cost model for query execution is often nonlinear.

#### Solving Nonlinear Equations

Because nonlinear equations can be more complex, we often use special methods to find their solutions:

1. **Graphical Method:** Plot the equation on a graph and look for points where the curve crosses the x-axis.
2. **Substitution and Elimination:** For systems of equations, substitute one equation into another or eliminate variables.
3. **Numerical Methods:** Use iterative methods like the Bisection Method or Newton-Raphson Method to find approximate solutions.



### 1.2 Types of Equations

1. **Algebraic Equations**
   - These are equations involving polynomial expressions.
   - **Example:** $$ \( x^3 - 6x^2 + 11x - 6 = 0 \) $$
   - They can be solved using various algebraic methods or numerical techniques.

2. **Transcendental Equations**
   - These are equations that involve transcendental functions such as exponential, logarithmic, trigonometric, or their combinations.
   - **Example:** \( e^x - 3x = 0 \)
   - These often require numerical methods for solutions since they cannot generally be solved algebraically.

3. **Trigonometric Equations**
   - These involve trigonometric functions.
   - **Example:** \( sin(x) = x^2 \)
   - Trigonometric identities and numerical methods are often used to solve these.

4. **Exponential Equations**
   - These equations have variables in the exponent.
   - **Example:** \( 2^x = 10 \)
   - Solved by taking logarithms or using numerical methods.

5. **Logarithmic Equations**
   - These involve logarithmic functions.
   - **Example:** \( log(x) = 2 - x \)
   - Solved using properties of logarithms and numerical techniques.

6. **Piecewise Equations**
   - These are defined by different expressions in different intervals.
   - **Example:** 

$$
f(x) = 
\begin{cases} 
x^2 & \text{if } x \leq 0 \\
\sqrt{x} & \text{if } x > 0 
\end{cases}
$$

   - Solutions depend on the piecewise definition and might require different approaches for each piece.
