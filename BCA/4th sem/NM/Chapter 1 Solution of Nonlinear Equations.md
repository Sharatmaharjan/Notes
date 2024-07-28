### Chapter 1: Solution of Nonlinear Equations
- Introduction
- Types of Equations
- Errors in Computing
- The Bisection Method
- The Method of False Position
- Newton- Raphson Method
- Solution of System of Nonlinear Equation
- Fixed Point Iteration and Convergence

  #### Introduction
  ### Solution of Nonlinear Equations

#### Introduction

Nonlinear equations are equations in which the unknown variable(s) appear to a power other than one and/or there is a product of variables. These equations are ubiquitous in scientific and engineering problems. Solving nonlinear equations involves finding the values of the variables that satisfy the equation. Unlike linear equations, nonlinear equations can have multiple solutions, no solutions, or infinitely many solutions.

#### Types of Equations

1. **Algebraic Equations**
   - These are equations involving polynomial expressions.
   - **Example:** \( x^3 - 6x^2 + 11x - 6 = 0 \)
   - They can be solved using various algebraic methods or numerical techniques.

2. **Transcendental Equations**
   - These are equations that involve transcendental functions such as exponential, logarithmic, trigonometric, or their combinations.
   - **Example:** \( e^x - 3x = 0 \)
   - These often require numerical methods for solutions since they cannot generally be solved algebraically.

3. **Trigonometric Equations**
   - These involve trigonometric functions.
   - **Example:** \( \sin(x) = x^2 \)
   - Trigonometric identities and numerical methods are often used to solve these.

4. **Exponential Equations**
   - These equations have variables in the exponent.
   - **Example:** \( 2^x = 10 \)
   - Solved by taking logarithms or using numerical methods.

5. **Logarithmic Equations**
   - These involve logarithmic functions.
   - **Example:** \( \log(x) = 2 - x \)
   - Solved using properties of logarithms and numerical techniques.

6. **Piecewise Equations**
   - These are defined by different expressions in different intervals.
   - **Example:** 
     \[
     f(x) = 
     \begin{cases} 
     x^2 & \text{if } x \leq 0 \\
     \sqrt{x} & \text{if } x > 0 
     \end{cases}
     \]
   - Solutions depend on the piecewise definition and might require different approaches for each piece.
