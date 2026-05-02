%Ecehelon and reduced echelon form
A = [-2 1 4 -3 1 10; 1 0 4 3 -1 1; -1 7 -8 3 1 -2; 5 -1 0 -3 4 4; 1 1 4 0 1 -6];
A([1 2],:) = A([2 1],:);
disp("After Row Swap: ")
disp("A = ")
disp(A)
A(2,:) = A(2,:) + 2*A(1,:);
A(3,:) = A(3,:) + A(1,:);
A(4,:) = A(4,:) - 5*A(1,:);
A(5,:) = A(5,:) - A(1,:);
disp("After First Elimination Step: ")
disp("A = ")
disp(A)
A(3,:) = A(3,:) - 7*A(2,:);
A(4,:) = A(4,:) + A(2,:);
A(5,:) = A(5,:) - A(2,:);
disp("After second Elimination Step: ")
disp("A = ")
disp(A)
A(3,:) = -1/88*A(3,:);
A(4,:) = A(4,:) + 8*A(3,:);
A(5,:) = A(5,:) + 12*A(3,:);
disp("After third Elimination Step: ")
disp("A = ")
disp(A)
A(4,:) = -11/150*A(4,:);
A(5,:) = A(5,:) + 87/22*A(4,:);
disp("After fourth Elimination Step: ")
disp("A = ")
disp(A)
A(5,:) = -100/9*A(5,:);
disp("After fifth Elimination Step: ")
disp("The echelon from: ")
disp("A = ")
disp(A)
A(4,:) = A(4,:) + 27/50*A(5,:);
A(3,:) = A(3,:) + 7/88*A(5,:);
A(2,:) = A(2,:) + A(5,:);
A(1,:) = A(1,:) + A(5,:);
disp("After sixth Elimination Step: ")
disp("A = ")
disp(A)

A(1,:) = A(1,:) - 3*A(4,:);
A(2,:) = A(2,:) - 3*A(4,:);
A(3,:) = A(3,:) - 15/88*A(4,:);
disp("After seventh Elimination Step: ")
disp("A = ")
disp(A)

A(2,:) = A(2,:) - 12*A(3,:);
A(1,:) = A(1,:) - 4*A(3,:);
A(abs(A) < 1e-10) = 0;
format rat;
disp("After eigth Elimination Step: ")
disp("The reduced-echelon from: ")
disp("A = ")
disp(A)

 solution = A(:,6);
x1 = solution(1);
x2 = solution(2);
x3 = solution(3);
x4 = solution(4);
x5 = solution(5);
format rat;
fprintf('x1 = %g\n', x1)
fprintf('x2 = %g\n', x2)
fprintf('x3 = %g\n', x3)
fprintf('x4 = %g\n', x4)
fprintf('x5 = %g\n', x5)

%Inverse, Determinant and adjoint

Inverse = eye(5);

Inverse([1 2],:) = Inverse([2 1],:);
Inverse(2,:) = Inverse(2,:) + 2*Inverse(1,:);
Inverse(3,:) = Inverse(3,:) + Inverse(1,:);
Inverse(4,:) = Inverse(4,:) - 5*Inverse(1,:);
Inverse(5,:) = Inverse(5,:) - Inverse(1,:);

Inverse(3,:) = Inverse(3,:) - 7*Inverse(2,:);
Inverse(4,:) = Inverse(4,:) + Inverse(2,:);
Inverse(5,:) = Inverse(5,:) - Inverse(2,:);

Inverse(3,:) = -1/88*Inverse(3,:);
Inverse(4,:) = Inverse(4,:) + 8*Inverse(3,:);
Inverse(5,:) = Inverse(5,:) + 12*Inverse(3,:);

Inverse(4,:) = -11/150*Inverse(4,:);
Inverse(5,:) = Inverse(5,:) + 87/22*Inverse(4,:);

Inverse(5,:) = -100/9*Inverse(5,:);
Inverse(4,:) = Inverse(4,:) + 27/50*Inverse(5,:);
Inverse(3,:) = Inverse(3,:) + 7/88*Inverse(5,:);
Inverse(2,:) = Inverse(2,:) + Inverse(5,:);
Inverse(1,:) = Inverse(1,:) + Inverse(5,:);

Inverse(1,:) = Inverse(1,:) - 3*Inverse(4,:);
Inverse(2,:) = Inverse(2,:) - 3*Inverse(4,:);
Inverse(3,:) = Inverse(3,:) - 15/88*Inverse(4,:);

Inverse(2,:) = Inverse(2,:) - 12*Inverse(3,:);
Inverse(1,:) = Inverse(1,:) - 4*Inverse(3,:);

disp("The inversem is: ")
disp("Inverse = ")
disp(Inverse)

Adjoint = det([-2 1 4 -3 1;
      1 0 4 3 -1;
     -1 7 -8 3 1;
      5 -1 0 -3 4;
      1 1 4 0 1]);
     
disp("The determinant is: ")
disp("Determinant = ")
disp(Inverse)
Adjoint = Adjoint*Inverse;

disp("The adjoint is: ")
disp("Adjoint = ")
disp(Inverse)

