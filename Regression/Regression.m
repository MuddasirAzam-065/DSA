format rat
% 1. Read the data from the CSV file into a table
data = readtable('MPG DateSet.csv');

% 2. Extract the number of rows
n = height(data);

% 3. Create matrix A: 
% The first column is one.
A = [ones(n, 1), data.HorsePower, data.Weight];

% 4. Create matrix B:
% Contains the MPG values
B = data.MPG;

%Calculating for regression

AT = transpose(A);
A1 = (AT*A);
B1 = (AT*B);
AUG = [A1,B1];
R = rref(AUG);
disp(R);

% Extract coefficients from the last column of R
beta0 = R(1, 4);
beta1 = R(2, 4);
beta2 = R(3, 4);

% Display the model
fprintf('Regression Model: MPG = %.4f + (%.4f * HP) + (%.4f * Weight)\n', beta0, beta1, beta2);

% Example: Predict MPG for a car with 150 HP and 3000 Weight
sample_HP = 150;
sample_Weight = 3000;
predicted_MPG = beta0 + (beta1 * sample_HP) + (beta2 * sample_Weight);

fprintf('Predicted MPG for 150HP and 3000lb: %.2f\n', predicted_MPG);

%Calculating Error and Root Mean Square.
X = [beta0; beta1; beta2];
ErrorV = B - A*X;
RMS = rms(ErrorV);
MIN = min(B);
MAX = max(B);
NomalizedRMS = RMS/(MAX - MIN);

disp(RMS);
disp(NomalizedRMS);
% 3. Plotting the 3D Graph
figure('Color', 'w');
scatter3(data.HorsePower, data.Weight, data.MPG, 'filled', 'MarkerFaceColor', 'b');
hold on;

% Create the regression surface
hp_vec = linspace(min(data.HorsePower), max(data.HorsePower), 20);
wt_vec = linspace(min(data.Weight), max(data.Weight), 20);
[HP, WT] = meshgrid(hp_vec, wt_vec);
MPG_Surface = beta0 + (beta1 * HP) + (beta2 * WT);

% Plot the plane
surf(HP, WT, MPG_Surface, 'FaceAlpha', 0.4, 'EdgeColor', 'black');

% Labeling
xlabel('Horse Power');
ylabel('Weight');
zlabel('MPG');
title('MPG Regression Model');
grid on;
view(3);


